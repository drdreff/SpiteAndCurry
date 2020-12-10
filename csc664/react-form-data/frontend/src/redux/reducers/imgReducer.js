const imgReducer = (state = {image: '', id: 0}, action) => {

    switch(action.type) {
      case 'SET_IMAGE':
        return {image: action.image, id: action.id };
      default:
        return state;
    }

};

export default imgReducer;
