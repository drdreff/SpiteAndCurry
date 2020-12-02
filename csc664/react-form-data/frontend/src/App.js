import React, { Component } from 'react';
import axios from 'axios';
import Grid from '@material-ui/core/Grid';
import CssBaseline from '@material-ui/core/CssBaseline';
import { makeStyles } from '@material-ui/core/styles';
import ViewPane from './panes/viewpane'
import SearchPane from './panes/searchpane'
import Sidebar from './panes/sidebar'
import ImgScroll from './panes/imgscroll'
import Typography from '@material-ui/core/Typography';
import Box from '@material-ui/core/Box';
import ImageUploadModal from './modals/imgUploadModal';
import MakeFacetModal from './modals/facetModal';

export default function App() {

  return (
    <>

    <Box>
    <CssBaseline />
    <Sidebar />
    <ImageUploadModal />
    <MakeFacetModal />
    </Box>
    </>
  );
}

  // state = {
  //   title: '',
  //   content: '',
  //   image: null
  // };
  //
  // handleChange = (e) => {
  //   this.setState({
  //     [e.target.id]: e.target.value
  //   })
  // };
  //
  // handleImageChange = (e) => {
  //   this.setState({
  //     image: e.target.files[0]
  //   })
  // };
  //
  // handleSubmit = (e) => {
  //   e.preventDefault();
  //   console.log(this.state);
  //   let form_data = new FormData();
  //   form_data.append('image', this.state.image, this.state.image.name);
  //   form_data.append('title', this.state.title);
  //   form_data.append('content', this.state.content);
  //   let url = 'http://localhost:8000/api/posts/';
  //   axios.post(url, form_data, {
  //     headers: {
  //       'content-type': 'multipart/form-data'
  //     }
  //   })
  //       .then(res => {
  //         console.log(res.data);
  //       })
  //       .catch(err => console.log(err))
  // };

// <div className="App">
//   <Grid container direction="row" justify="center" alignItems="stretch">
//     <Grid item xs={6}>
//       <Grid container direction="column" justify="center" alignItems="center">
//       <Grid item xs={6}>
//       <form onSubmit={this.handleSubmit}>
//         <p>
//           <input type="text" placeholder='Title' id='title' value={this.state.title} onChange={this.handleChange} required/>
//         </p>
//         <p>
//           <input type="text" placeholder='Content' id='content' value={this.state.content} onChange={this.handleChange} required/>
//         </p>
//         <p>
//           <input type="file"
//               id="image"
//               accept="image/png, image/jpeg"  onChange={this.handleImageChange} required/>
//         </p>
//       <input type="submit"/>
//     </form>
//     </Grid>
//     </Grid>
//   </Grid>
//   </Grid>
// </div>
