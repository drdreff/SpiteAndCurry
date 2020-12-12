import React, { Component } from 'react';
import axios from 'axios';
import Grid from '@material-ui/core/Grid';
import { makeStyles } from '@material-ui/core/styles';
import Typography from '@material-ui/core/Typography';
import Container from '@material-ui/core/Container';
import spiri from '../test_images/143336_HYA0IdNQ_gSRB9hZ.png'
import Box from '@material-ui/core/Box';
import { connect } from 'react-redux';
import { setImage } from '../redux/actions';
import SearchGraph from './searchgraph';
import * as d3 from "d3";



const api = axios.create({
  baseURL: `http://localhost:8000/api/`
})

class SearchPane extends Component {

  constructor(props) {
    super(props);
    this.state = {
      nodes: [],
      links: []
    }
    api.get('imgfiles/'+this.props.imageID+'/get_graph/?facet='+this.props.facetID).then(res => {
      console.log(res.data)
      this.setState({nodes: res.data.nodes, links: res.data.links})
    })
  }

  componentDidUpdate(prevProps, prevState) {
    if (prevProps.startSearch != this.props.startSearch) {
      api.get('imgfiles/'+this.props.imageID+'/get_graph/?facet='+this.props.facetID).then(res => {
        console.log(res.data)
        this.setState({nodes: res.data.nodes, links: res.data.links})
      })
    }
  }

  render() {
  return (
    <Box style={{    border: 3,
        borderStyle: 'inset',
        height: '78vh',
        backgroundColor: '#cfe8fc',
        borderColor: 'green'}}>
      <SearchGraph nodelist={this.state.nodes} linklist={this.state.links} />
    </Box>
  );}

}

const mapStateToProps = (state) => {
  return {
    imageID: state.searchReducer.imageID,
    facetID: state.searchReducer.facetID,
    startSearch: state.searchReducer.startSearch
  }
}

export default connect(mapStateToProps, { setImage })(SearchPane)
