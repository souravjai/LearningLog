/** 
I came across a article that explained reduce more throughly
 */
/**
 * @template T, U
 * @param {(previousValue: U, currentValue: T, currentIndex: number, array: T[]) => U} callbackFn
 * @param {U} [initialValue]
 * @return {Array<U>}
 */
 Array.prototype.myReduce = function (callbackFn, initialValue) {
  
    if(initialValue === undefined && this.length === 0){
      throw TypeError("Reduce of empty array with no initial value") 
    }
  
    let retVal = initialValue !== undefined ? initialValue : this[0];
    let index = initialValue !== undefined ? 0 : 1;
    
    for(;index<this.length;index++){
      if(this.hasOwnProperty(index))
        retVal = callbackFn(retVal,this[index],index,this);
    }
  
    return retVal;
  };




/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
    let res = init;

    for (let i = 0; i < nums.length; i++) {
        res = fn(res, nums[i]);
    }

    return res;

};