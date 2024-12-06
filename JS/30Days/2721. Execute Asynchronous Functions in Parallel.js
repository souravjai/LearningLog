/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
 var promiseAll = function(functions=[]) {

    return new Promise((resolve,reject)=>{
        let result = new Array(functions.length);
        let count = 0;

        functions.forEach((fn,idx)=>{
            fn()
            .then(res=>{
                result[idx] = res;
                count++;
                if(count === functions.length){
                    resolve(result);
                }
            })
            .catch(err=>reject(err));
        })
    })
    
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */