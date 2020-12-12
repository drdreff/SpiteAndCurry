import React, { Component } from 'react';
import axios from 'axios';
import RegionSelect from 'react-region-select';
import Grid from '@material-ui/core/Grid';
import { makeStyles } from '@material-ui/core/styles';
import Typography from '@material-ui/core/Typography';
import Container from '@material-ui/core/Container';
import TextField from '@material-ui/core/TextField';
import Box from '@material-ui/core/Box';
import MenuItem from '@material-ui/core/MenuItem';
import Button from '@material-ui/core/Button';
import IconButton from '@material-ui/core/IconButton';
import Icon from '@material-ui/core/Icon';
import CheckIcon from '@material-ui/icons/Check';
import ButtonBase from '@material-ui/core/ButtonBase';
import objectAssign from 'object-assign';
import { connect } from 'react-redux';
import { regionModal, setRegion, setFacet, setSearch, searchModal } from '../redux/actions';




const api = axios.create({
  baseURL: `http://localhost:8000/api/`
})

class ViewPane extends Component {

  constructor (props) {
		super(props);
		this.regionRenderer = this.regionRenderer.bind(this);
		this.onChange = this.onChange.bind(this);
		this.state = {
			regions: [],
      facets: [],
      crntFacet: '',
      imgRegions: [],
      width: 0,
      height: 0
		};
    api.get('facets/').then(res => {
      console.log(res.data)
      this.setState({facets: res.data})
    });
    this.myRef = React.createRef();
	}

  componentDidUpdate(prevProps, prevState) {
    if (prevProps.image !== this.props.image){
      api.get('imgfiles/'+this.props.id+'/regions/').then(res => {
        console.log(res.data)
        this.setState({imgRegions: res.data})
      })
      api.get('facets/').then(res => {
        console.log(res.data)
        this.setState({facets: res.data})
      });
    }
   if (prevProps.reload !== this.props.reload){
     api.get('imgfiles/'+this.props.id+'/regions/').then(res => {
       console.log(res.data)
       this.setState({imgRegions: res.data})
     })
     api.get('facets/').then(res => {
       console.log(res.data)
       this.setState({facets: res.data})
     });
   }
  }

	onChange (regions) {
		this.setState({
			...this.state,
      regions: regions
		});
	}

  searchHandle = (e) => {
    let temp = {imageID: this.props.id, facetID: e.facets}
    this.props.setSearch(temp);
    this.props.searchModal();
  }

  clickHandle = () => {
    this.props.setRegion(this.state.regions[0]);
    this.props.setFacet(this.state.crntFacet);
    this.props.regionModal();
  }

  onFacetSelect = (e) => {
    e.preventDefault();
    console.log(e.target.value)
    this.setState({
      ...this.state,
      crntFacet: e.target.value,
    })
  }

	regionRenderer (regionProps) {
		if (!regionProps.isChanging) {
			return (
				<div style={{ position: 'absolute', right: 0, bottom: '-2em' }}>
        <Grid container direction="row">
          <Grid item>
					<select
          onChange={(event) => this.onFacetSelect(event)}
          value={this.state.crntFacet}>
						{this.state.facets.map((option) => (
              <option key={option.id} value={option.id}>
                {option.name}
              </option>
            ))} default>
					</select>
          </Grid>
          <Grid item>
          <IconButton
          variant="contained"
          color="primary"
          size="small"
          onClick={this.clickHandle}>
            <CheckIcon/>
          </IconButton>
          </Grid>
          </Grid>
				</div>
			);
		}
	}

  componentDidMount() {
    this.setState({
      ...this.state,
      width: document.getElementById(this.myRef).clientWidth,
      height: document.getElementById(this.myRef).clientHeight
    })
  }

render(){

  const regionStyle = {
			background: 'rgba(255, 0, 0, 0.5)'
		};



  return (

    <div id={this.myRef} style={{border: 3,
        borderStyle: 'inset',
        height: '78vh',
        backgroundColor: '#cfe8fc',
        borderColor: 'green',}}>
        <Grid container
              spacing={0}
              direction="column"
              alignItems="center"
              justify="center"
              style={{minHeight: '100%'}}>
              <Grid item>
              <RegionSelect
    						maxRegions={1}
    						regions={this.state.regions}
                regionStyle={regionStyle}
    						constraint
    						onChange={this.onChange}
    						regionRenderer={this.regionRenderer}
    						style={{ border: '1px solid black' }}
    					>
              {this.state.imgRegions.map((fRegion) => (

                  <ButtonBase
                    focusRipple
                    key={fRegion.id}
                    style={{
                      position: 'absolute',
                      left: fRegion.x,
                      top: fRegion.y,
                      width: fRegion.width,
                      height: fRegion.height,
                      opacity: 0.5,
                      backgroundColor: 'grey',
                      border: '1px solid black',
                    }}
                    onClick={() => this.searchHandle(fRegion)}>
                    <div style={{
                    }}>
                    </div>
                    </ButtonBase>
              ))}
          <img src={this.props.image} style={{ maxWidth: this.state.width, maxHeight: this.state.height }} />
          </RegionSelect>
              </Grid>
          </Grid>

    </div>
  );}


}

const mapStateToProps = (state) => {
  return {
    image: state.imgReducer.image,
    id: state.imgReducer.id,
    reload: state.modalReducer.viewUpdate
  }
}

export default connect(mapStateToProps, { regionModal, setRegion, setFacet, setSearch, searchModal })(ViewPane)
