import { combineReducers } from 'redux';
import imgReducer from './reducers/imgReducer';
import modalReducer from './reducers/modalReducer';

const allReducer = combineReducers({
  imgReducer,
  modalReducer
});

export default allReducer;
