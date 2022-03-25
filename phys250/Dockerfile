ARG BASE_CONTAINER=jupyter/scipy-notebook
FROM $BASE_CONTAINER
LABEL author="Mark Davis"
USER root
RUN ln -sf /usr/share/zoneinfo/America/Los_Angeles /etc/localtime
#RUN pip install pandas numpy matplotlib plotly
# Switch back to jovyan to avoid accidental container runs as root
USER $NB_UID
