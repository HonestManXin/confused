function getlength(element)
{
	alert(element.length);
}

$(document).ready(function(){
	//alert($('div:contains(id)').length);
	getlength($('div:has(div)'));
});