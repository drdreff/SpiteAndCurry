import React, {Component} from 'react';
import Button from '@material-ui/core/Button';
import FormGroup from '@material-ui/core/FormGroup';
import FormControlLabel from '@material-ui/core/FormControlLabel';
import Checkbox from '@material-ui/core/Checkbox';
import Dialog from '@material-ui/core/Dialog';
import DialogActions from '@material-ui/core/DialogActions';
import DialogContent from '@material-ui/core/DialogContent';
import DialogContentText from '@material-ui/core/DialogContentText';
import DialogTitle from '@material-ui/core/DialogTitle';
import objectAssign from 'object-assign';
import axios from 'axios';
import { connect } from 'react-redux';
import { regionModal, updateView } from '../redux/actions';

const api = axios.create({
  baseURL: `http://localhost:8000/api/`
})

class RegionCreateModal extends Component {

  constructor(props) {
    super(props);
    this.state = {
      unlinked: [],
      checkedImages: [],
      linkedImages: []
    }
    api.get('imgfiles/'+ this.props.imgid + '/unlinked/?facet=' + this.props.facet).then(res => {
      console.log(res.data)
      this.setState({...this.state, unlinked: res.data})
    });
    this.mapImages();
  }

  mapImages = () => {
    this.state = { ...this.state,
                    checkedImages: this.state.unlinked.map(
                      (image) => ({
                        key: image.id,
                        checked: false
                      }),
                      {}
                    )}
    console.log(this.state);
  }

  updateUnlinked = () => {
    api.get('imgfiles/'+ this.props.imgid + '/unlinked/?facet=' + this.props.facet).then(res => {
      console.log(res.data)
      this.setState({...this.state, unlinked: res.data})
    });
    this.mapImages();
  }

  handleClose = () => {
    this.state = { ...this.state,
                    linkedImages: this.state.checkedImages.filter(img => img.checked === true).map(
                      (image) => ({
                        key: image.key,
                      }),
                      {}
                    )}
    console.log(this.state.linkedImages.map(arr => {return arr.key}));
  }

  checkedImage = (event) => {
    const item = Number(event.target.id);
    console.log(item);
    const checked = event.target.checked;
    console.log(checked);
    this.setState(prevState => ({...prevState,
                                checkedImages: prevState.checkedImages.map(element => ((element.key === item) ? Object.assign({}, element, {checked: checked}) : element ))
                              }));
    console.log(this.state.checkedImages.map(element => ((element.key === item) ? Object.assign({}, element, {checked: checked}) : element )));
  }

  handleSubmit = (e) => {
    e.preventDefault();
    console.log(this.state);
    let form_data = new FormData();
    let temp = '' + Math.round(this.props.x) + '%';

    form_data.append('x', temp);
    temp = String(Math.round(this.props.y)) + '%';

    form_data.append('y', temp);
    temp = String(Math.round(this.props.width)) + '%';

    form_data.append('width', temp);
    temp = String(Math.round(this.props.height)) + '%';

    form_data.append('height', temp);
    form_data.append('facets', this.props.facet);
    form_data.append('image', this.props.imgid);
    let url = 'http://localhost:8000/api/regions/';
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
    temp = JSON.stringify({ linkedImages: this.state.checkedImages.filter(img => img.checked === true).map(arr => {return arr.key})})
    console.log(temp);
    axios.post('http://localhost:8000/api/imgfiles/'+ this.props.imgid + '/addlink/', temp, {
      headers: {
        'content-type': 'application/json'
      }
    })
              .then(res => {
                console.log(res.data);
              })
              .catch(err => console.log(err))
    this.props.updateView();
    this.props.regionModal();
  };


  _handleFacetChange = (e) => {
    e.preventDefault();
    console.log(e.target.value);
    this.setState({
      name: e.target.value,
    }, function(){console.log(this.state);});

  };

render () {
  return (
    <div>
      <Dialog open={this.props.open} onClose={this.handleClose()} onEnter={this.updateUnlinked} aria-labelledby="form-dialog-title">
        <DialogTitle id="form-dialog-title">Link Images</DialogTitle>
        <DialogContent>
          <DialogContentText>
            <FormGroup>
            {this.state.checkedImages.map((image) => (
              <FormControlLabel  control={<Checkbox id={image.key} checked={image.checked} onChange={this.checkedImage} />} label={image.key} />
            ))}
            </FormGroup>
          </DialogContentText>
        </DialogContent>
        <DialogActions>
          <Button onClick={this.props.regionModal} color="primary">
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
    open: state.modalReducer.regionModal,
    x: state.facetReducer.x,
    y: state.facetReducer.y,
    width: state.facetReducer.width,
    height: state.facetReducer.height,
    facet: state.facetReducer.facet,
    imgid: state.imgReducer.id
  }
}

export default connect(mapStateToProps, {regionModal, updateView})(RegionCreateModal)
