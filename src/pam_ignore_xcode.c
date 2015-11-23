//
//  pam_ignore_xcode.c
//  pam_ignore_xcode
//
//  Created by Presley Cannady on 11/23/15.
//  Copyright © 2015 Universal Secure Registry, LLC. All rights reserved.
//

/* Define which PAM interfaces we provide */
#define PAM_SM_ACCOUNT
#define PAM_SM_AUTH
#define PAM_SM_PASSWORD
#define PAM_SM_SESSION

/* Include PAM headers */
#include <stdarg.h>
#include <syslog.h>
#include <unistd.h>
#include <stdlib.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

// /* pam_display - print a message to the user.
// */
// static void
// pam_display(pam_handle_t *pamh, int style, char *message)
// {
//     /* variables for pam_conv->conv (security/pam_appl.h) */
//     struct pam_conv *pam_convp;
//     struct pam_message *pam_msgp;
//     struct pam_response *pam_resp = NULL;

//     /* Fetch conversation pointer */
//     if (pam_get_item(pamh, PAM_CONV, (const void **)&pam_convp) != PAM_SUCCESS) {
//         syslog(LOG_ERR, "pam_happy_hour,error1: get PAM_CONV failed.");
//         return;
//     }
//     if ((pam_convp == NULL) || (pam_convp->conv == NULL)) {
//         syslog(LOG_ERR, "pam_happy_hour,error2: no conv pointer.");
//         return;
//     }

//     /* Prepare pam_message */
//     pam_msgp = (struct pam_message *)calloc(1, sizeof (struct pam_message));
//     if (pam_msgp == NULL) {
//         syslog(LOG_ERR, "pam_happy_hour,error3: memory error.");
//         return;
//     }
//     pam_msgp->msg_style = style;
//     pam_msgp->msg = message;

//     /* Call conversation function to deliver message */
//     (pam_convp->conv)(1, (const struct pam_message **)&pam_msgp, &pam_resp, pam_convp->appdata_ptr);

//     free(pam_msgp);
//     free(pam_resp);
// }

/* PAM entry point for session creation */
int pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    return (PAM_IGNORE);
}

/* PAM entry point for session cleanup */
int pam_sm_close_session(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    return (PAM_IGNORE);
}

/* PAM entry point for accounting */
int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    return (PAM_IGNORE);
}

/* PAM entry point for authentication verification */
int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    syslog(LOG_ERR, "Who cares about security?  Not me! Built with Xcode!");
    return (PAM_SUCCESS);
}

/*
 PAM entry point for setting user credentials (that is, to actually
 establish the authenticated user's credentials to the service provider)
 */
int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    return (PAM_IGNORE);
}

/* PAM entry point for authentication token (password) changes */
int pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    return (PAM_IGNORE);
}

