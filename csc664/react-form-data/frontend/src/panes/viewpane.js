import React, { Component } from 'react';
import axios from 'axios';
import Grid from '@material-ui/core/Grid';
import { makeStyles } from '@material-ui/core/styles';
import Typography from '@material-ui/core/Typography';
import Container from '@material-ui/core/Container';
import spiri from '../test_images/143336_HYA0IdNQ_gSRB9hZ.png'
import Box from '@material-ui/core/Box';
import { connect } from 'react-redux';


const useStyles = makeStyles({
  paneDiv: {
    border: 3,
    borderStyle: 'inset',
    height: '90%',
    backgroundColor: '#cfe8fc',
    borderColor: 'green',
    justifyContent: 'center'

  }
})

const api = axios.create({
  baseURL: `http://localhost:8000/api/imgfiles/`
})

class ViewPane extends Component {

componentDidUpdate(prevProps, prevState) {
  if(prevProps.image !== this.props.image) {
    console.log('Image updated');
  }
}

render(){
  return (

    <Box style={{    border: 3,
        borderStyle: 'inset',
        height: '78vh',
        backgroundColor: '#cfe8fc',
        borderColor: 'green',
        display: 'flex',
        justifyContent: 'center'}}>
        <Container>
        <img src={this.props.image} />
        </Container>
    </Box>

  );}
}

const mapStateToProps = (state) => {
  return {
    image: state.imgReducer
  }
}

export default connect(mapStateToProps)(ViewPane)
