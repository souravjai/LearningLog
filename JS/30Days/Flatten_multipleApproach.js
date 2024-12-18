// In place without extra space
export default function flatten(value) {

  for (let i = 0; i < value.length; i++) {
    if (Array.isArray(value[i])) {
      value.splice(i, 1, ...value[i]);
      i--;
    }
  }
  return value;
}


// This is better as it does not take any extra stack space for method calls.

export default function flatten(value) {
  let retVal = []
  let copy = value.slice();

  while (copy.length > 0) {
    let item = copy.shift();

    if (Array.isArray(item)) {
      copy.unshift(...item);
    } else {
      retVal.push(item);
    }
  }

  return retVal;
}


/**
 * @param {Array<*|Array>} value
 * @return {Array}
 */
// This approach will cause problem when 1000 of nested level are present
export default function flatten(value) {
  let retVal = []

  value.forEach(val => {
    if (Array.isArray(val)) {
      retVal.push(...flatten(val))
    } else {
      retVal.push(val)
    }
  })

  return retVal;
}