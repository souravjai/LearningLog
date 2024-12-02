/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function (sentence, searchWord) {
    let idx = sentence.split(" ").findIndex(ele => ele.startsWith(searchWord));
    return idx == -1 ? idx : idx + 1;
};