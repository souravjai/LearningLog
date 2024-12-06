var TimeLimitedCache = function () {
    this.cache = new Map();
};
/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */



TimeLimitedCache.prototype.set = function (key, value, duration) {
    let isPresent = this.cache.has(key);

    if (isPresent) {
        clearTimeout(this.cache.get(key).timerId);
    }

    this.cache.set(key, {
        value,
        timerId: setTimeout(() => this.cache.delete(key), duration)
    });

    return isPresent;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
    return this.cache.get(key)?.value ?? -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
    return this.cache.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */