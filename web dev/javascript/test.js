class Todo{
    constructor(){
        this.todos = [];
    }
    add(item){
        this.todos.push(item);
    }
    deleteAll(){
        this.todos = [];
    }
    get(){
        return this.todos;
    }
    delete(item){
        this.todos=this.todos.splice(this.todos.indexOf(item),1);
    }
}

const list = new Todo();