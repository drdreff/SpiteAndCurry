const imgReducer = (state = '', action) => {

    switch(action.type) {
      case 'SET_IMAGE':
        state = action.image;
        return state;
      default:
        return state;
    }

};

export default imgReducer;
