/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
    let res = [];

    arr.forEach((item, i) => res.push(fn(item, i)));

    return res;
};