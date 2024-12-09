/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
 var chunk = function (arr, size) {
    return arr.reduce((acc, cur, ind) => {
        if ((ind % size) === 0) {
            acc.push([]);
        }
        acc.at(-1).push(cur);
        return acc;
    }, []);
};
