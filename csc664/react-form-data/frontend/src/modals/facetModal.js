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
import { facetModal } from '../redux/actions';

const api = axios.create({
  baseURL: `http://localhost:8000/api/facets/`
})

class MakeFacetModal extends Component {

  state = {
    facet: ''
  }

  handleClose = () => {
    this.state.facet = '';

  }

  handleSubmit = (e) => {
    e.preventDefault();
    console.log(this.state);
    let form_data = new FormData();
    form_data.append('name', this.state.facet);
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
      this.handleClose();
  };


  handleChange = (e) => {
    e.preventDefault();
    this.setState({
      [e.target.id]: e.target.value
    })
  };

render () {
  return (
    <div>
      <Dialog open={this.props.open} onClose={this.handleClose()} aria-labelledby="form-dialog-title">
        <DialogTitle id="form-dialog-title">Upload Image</DialogTitle>
        <DialogContent>
          <DialogContentText>
            Upload an image to the network, or Cancel.
          </DialogContentText>
                    <TextField id="filled-basic" label='Facet' onChange={(e) => this.handleChange(e)} />
        </DialogContent>
        <DialogActions>
          <Button onClick={this.props.facetModal} color="primary">
            Cancel
          </Button>
          <Button onClick={this.handleSubmit} color="primary">
            Submit
          </Button>
        </DialogActions>
      </Dialog>
    </div>
  );}
}

const mapStateToProps = (state) => {
  return {
    open: state.modalReducer.facet
  }
}

export default connect(mapStateToProps, {facetModal})(MakeFacetModal)
