/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    let res = [];

    arr.forEach((item, idx) => {
        if (fn(item, idx)) {
            res.push(item);
        }
    })

    return res;
};