import { useEffect } from "react";
import useNews from "./hooks/useNews";
import News from "./component/News";

import "./App.css";

export default function App() {
	const [ready, loading, newsList, getMoreNews, isAllNewsFetched] = useNews();

	useEffect(() => {
		if (ready) {
			getMoreNews();
		}
	}, [ready]);

	console.log(newsList);

	const mainContent =
		ready &&
		newsList.length !== 0 &&
		newsList.map((news) => <News key={news.id} {...news} />);

	return (
		<>
			<header>
				<h1>Hacker News Jobs Board</h1>
			</header>

			<div className='news-container'>
				{mainContent}
				{(!ready || !isAllNewsFetched()) && (
					<button onClick={getMoreNews}>
						{!ready || loading ? "Loading..." : "Load More jobs"}
					</button>
				)}
			</div>
		</>
	);
}
