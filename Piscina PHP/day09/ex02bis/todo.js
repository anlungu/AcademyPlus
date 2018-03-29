var ft_list;
var cookie = [];

$(document).ready(function () {
    $('#new').click(newTodo);
    $('#ft_list div').click(deleteTodo);
    ft_list = $('#ft_list');
    var tmp = document.cookie;
    if (tmp) {
        cookie = JSON.parse(tmp);
        cookie.forEach(function (e) {
            addTodo(e);
        });
    }
});

$(window).on('unload', function () {
    var todo = ft_list.children();
    var newCookie = [];
    for (var i = 0; i < todo.length; i++)
        newCookie.unshift(todo[i].innerHTML);
    document.cookie = JSON.stringify(newCookie);
});

function newTodo(){
    var todo = prompt("Introdu in lista", '');
    console.log(todo);
    if (todo != null && !isEmpty(todo)) {
        addTodo(todo)
    }
}

function isEmpty(str) {
    return str.replace(/^\s+|\s+$/gm,'').length == 0;
}

function addTodo(todo){
    ft_list.prepend($('<div>' + todo + '</div>').click(deleteTodo));
}

function deleteTodo(){
    if (confirm("Sterge element?")){
        this.remove();
    }
}