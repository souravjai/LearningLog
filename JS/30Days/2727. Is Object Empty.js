/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    // if(Array.isArray(obj)){
    //     return Array.length===0;
    // }
    return Object.keys(obj).length===0;
};