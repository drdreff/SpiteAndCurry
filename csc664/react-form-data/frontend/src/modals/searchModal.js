import React, {Component} from 'react';
import Button from '@material-ui/core/Button';
import TextField from '@material-ui/core/TextField';
import Dialog from '@material-ui/core/Dialog';
import DialogActions from '@material-ui/core/DialogActions';
import DialogContent from '@material-ui/core/DialogContent';
import DialogContentText from '@material-ui/core/DialogContentText';
import DialogTitle from '@material-ui/core/DialogTitle';
import axios from 'axios';
import { connect } from 'react-redux';
import { searchModal, startSearch } from '../redux/actions';

class SearchModal extends Component {

  handleClose = () => {

  }

  search = () => {
    this.props.startSearch();
    this.props.searchModal();
  }

  handleSubmit = (e) => {
    e.preventDefault();
    console.log(this.state);
    let form_data = new FormData();
    form_data.append('name', this.state.name);
    let url = 'http://localhost:8000/api/facets/';
    console.log(form_data);
      axios.post(url, form_data, {
        headers: {
          'content-type': 'multipart/form-data'
        }
      })
          .then(res => {
            console.log(res.data);
          })
          .catch(err => console.log(err))
    this.props.searchModal();
  };

render () {
  return (
    <div>
      <Dialog open={this.props.open} onClose={this.handleClose()} aria-labelledby="form-dialog-title">
        <DialogTitle id="form-dialog-title">Facet Selection</DialogTitle>
        <DialogContent>
          <DialogContentText>
            You have selected facet: {this.props.facetID} on image: {this.props.imageID}. Would you like to delete this region, or search from this image?
          </DialogContentText>
        </DialogContent>
        <DialogActions>
          <Button onClick={this.props.searchModal} color="primary" disabled>
            Delete
          </Button>
          <Button onClick={this.props.searchModal} color="primary">
            Cancel
          </Button>
          <Button onClick={this.search} color="primary">
            Search
          </Button>
        </DialogActions>
      </Dialog>
    </div>
  );}
}

const mapStateToProps = (state) => {
  return {
    facetID: state.searchReducer.facetID,
    imageID: state.searchReducer.imageID,
    open: state.modalReducer.searchModal
  }
}

export default connect(mapStateToProps, {searchModal, startSearch})(SearchModal)
