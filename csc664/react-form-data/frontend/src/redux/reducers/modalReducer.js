
const modalReducer = (state = {image: false, facet: false, regionModal: false, searchModal: false, imgUpdate: 0, viewUpdate: 0}, action) => {

  let temp = null;

    switch(action.type) {
      case 'IMAGE_MODAL':
        temp = !state.image;
        return { ...state, image: temp};
      case 'FACET_MODAL':
        temp = !state.facet;
        return { ...state, facet: temp};
      case 'REGION_MODAL':
        temp = !state.regionModal;
        return { ...state, regionModal: temp};
      case 'SEARCH_MODAL':
        temp = !state.searchModal;
        return {...state, searchModal: temp};
      case 'UPDATE_SCROLL':
        temp = state.imgUpdate + 1;
        return { ...state, imgUpdate: temp};
      case 'UPDATE_VIEW':
        temp = state.viewUpdate + 1;
        return { ...state, viewUpdate: temp};
      default:
        return state;
    }

};

export default modalReducer;
