/**
* @param {Function} fn
* @return {Function}
*/
function memoize(fn) {
    let mp = {};
    return function (...args) {
        let val = args.toString();
        if (mp[val] === undefined) {
            mp[val] = fn(...args);
        }
        return mp[val];
    }
}


/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */