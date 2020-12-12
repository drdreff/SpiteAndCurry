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
import { imageModal, updateScroll } from '../redux/actions';

const api = axios.create({
  baseURL: `http://localhost:8000/api/imgfiles/`
})

class ImageUploadModal extends Component {

  state = {
    file: null
  }

  handleClose = () => {
    this.state.image = null;

  }

  handleSubmit = (e) => {
    e.preventDefault();
    console.log(this.state);
    let form_data = new FormData();
    form_data.append('image', this.state.file);
    let url = 'http://localhost:8000/api/imgfiles/';
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
      this.props.updateScroll();
      this.props.imageModal();
  };


  handleImageChange = (e) => {
    this.setState({
      file: e.target.files[0]
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
                    <input type="file"
                        id="image"
                        accept="image/png, image/jpeg"  onChange={this.handleImageChange} required/>
        </DialogContent>
        <DialogActions>
          <Button onClick={this.props.imageModal} color="primary">
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
    open: state.modalReducer.image
  }
}

export default connect(mapStateToProps, {imageModal, updateScroll})(ImageUploadModal)
