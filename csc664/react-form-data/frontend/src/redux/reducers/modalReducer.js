
const modalReducer = (state = {image: false, facet: false}, action) => {

  let temp = null;

    switch(action.type) {
      case 'IMAGE_MODAL':
        temp = !state.image;
        return { ...state, image: temp};
      case 'FACET_MODAL':
        temp = !state.facet;
        return { ...state, facet: temp};
      default:
        return state;
    }

};

export default modalReducer;
