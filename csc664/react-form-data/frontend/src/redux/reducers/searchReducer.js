const searchReducer = (state = {imageID: 0, facetID: 0, startSearch: 0}, action) => {

    switch(action.type) {
      case 'SET_SEARCH':
        return {...state, imageID: action.imageID, facetID: action.facetID };
      case 'START_SEARCH':
          return {...state, startSearch: state.startSearch + 1};
      default:
        return state;
    }

};

export default searchReducer;
