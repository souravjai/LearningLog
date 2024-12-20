import { useState, useEffect, useRef } from "react";

export default function useNews() {
    const MAX_NEWS_LOAD = 11;

    const newsIds = useRef([]);
    const lastLoaded = useRef(0);

    const [ready, setReady] = useState(false);
    const [loading, setLoading] = useState(false);
    const [newsList, setNewsList] = useState([]);

    useEffect(() => {
        fetch("https://hacker-news.firebaseio.com/v0/jobstories.json")
            .then((response) => response.json())
            .then((json) => {
                newsIds.current = json;
                setReady(true);
            });
    }, []);


    function getMoreNews() {
        setLoading(true);
        const startIndex = lastLoaded.current;
        const endIndex = lastLoaded.current + MAX_NEWS_LOAD;
        lastLoaded.current = endIndex;

        const currentNewsId = newsIds.current.slice(startIndex, endIndex);

        const fetchNewsPromises = currentNewsId.map((id) => {
            return fetch(
                `https://hacker-news.firebaseio.com/v0/item/${id}.json`,
            ).then((res) => res.json());
        });

        Promise.allSettled(fetchNewsPromises).then((results) => {
            const latestNews = results
                .filter((result) => result.status === "fulfilled")
                .map((result) => result.value);

            setNewsList((prev) => [...prev, ...latestNews]);
            setLoading(false);
        });
    }

    function isAllNewsFetched() {
        return lastLoaded.current >= newsIds.current.length;
    }
    return [ready, loading, newsList, getMoreNews, isAllNewsFetched];
}
