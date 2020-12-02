import React, { Component } from 'react';
import axios from 'axios';
import Grid from '@material-ui/core/Grid';
import { makeStyles } from '@material-ui/core/styles';
import Typography from '@material-ui/core/Typography';
import Container from '@material-ui/core/Container';
import Box from '@material-ui/core/Box';
import GridList from '@material-ui/core/GridList';
import GridListTile from '@material-ui/core/GridListTile';
import GridListTileBar from '@material-ui/core/GridListTileBar';
import IconButton from '@material-ui/core/IconButton';
import StarBorderIcon from '@material-ui/icons/StarBorder';
import { setImage } from '../redux/actions';
import { connect } from 'react-redux';

const api = axios.create({
  baseURL: `http://localhost:8000/api/imgfiles/`
})

class ImgScroll extends Component {

  state = {
    imagelist: []
  }

  constructor() {
    super();
    api.get('/').then(res => {
      console.log(res.data)
      this.setState({imagelist: res.data})
    })
  }

  handleSetImage = (image) => {
    this.props.setImage(image)
  }

  render(){
  return (
    <div style={{height: "100%"}}>
          <GridList style={{flexWrap: 'nowrap',
                            transform: 'translateZ(0)',
                          }} cols={3}>
            {this.state.imagelist.map((tile) => (
              <GridListTile key={tile.id}>
                <img resizeMode="contain" src={tile.image} alt={tile.name} />
                <GridListTileBar
                  title={tile.name}
                  actionIcon={
                    <IconButton aria-label={`star ${tile.name}`} onClick={() => {this.handleSetImage(tile.image)}}>
                      <StarBorderIcon style={{}} />
                    </IconButton>
                  }
                />
              </GridListTile>
            ))}
          </GridList>
    </div>
  );}
}

export default connect(null, {setImage})(ImgScroll)
