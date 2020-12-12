const regionReducer = (state = {x: 0, y: 0, width: 0, height: 0, facet: 0 }, action) => {

  let temp = null;

    switch(action.type) {
      case 'SET_REGION':
        return {...state,
                x: action.x,
                y: action.y,
                width: action.width,
                height: action.height};
      case 'SET_FACET':
        temp = action.facet;
        return {...state, facet: temp};
      default:
        return state;
    }

};

export default regionReducer;
