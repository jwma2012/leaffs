public void handle(JobEvent event) {
  if (LOG.isDebugEnabled()) {
    LOG.debug("Processing " + event.getJobId() + " of type "
        + event.getType());
  }
  try {
    writeLock.lock();
    JobStateInternal oldState = getInternalState();
    try {
       getStateMachine().doTransition(event.getType(), event);   // 获取job的当前的状态机，根据当前消息event进行状态变换。
    } catch (InvalidStateTransitonException e) {                 // 会跳转至 StateMachine 实现的 doTransition()函数。
      LOG.error("Can't handle this event at current state", e);
      addDiagnostic("Invalid event " + event.getType() +
          " on Job " + this.jobId);
      eventHandler.handle(new JobEvent(this.jobId,
          JobEventType.INTERNAL_ERROR));
    }
    //notify the eventhandler of state change
    if (oldState != getInternalState()) {
      LOG.info(jobId + "Job Transitioned from " + oldState + " to "
               + getInternalState());
      rememberLastNonFinalState(oldState);
    }
  }

  finally {
    writeLock.unlock();
  }
}