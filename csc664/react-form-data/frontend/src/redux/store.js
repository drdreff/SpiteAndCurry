import { combineReducers } from 'redux';
import imgReducer from './reducers/imgReducer';
import modalReducer from './reducers/modalReducer';
import facetReducer from './reducers/facetReducer';
import searchReducer from './reducers/searchReducer';

const allReducer = combineReducers({
  imgReducer,
  modalReducer,
  facetReducer,
  searchReducer
});

export default allReducer;
