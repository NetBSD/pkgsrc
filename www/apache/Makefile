# New ports collection makefile for:    apache
# http://www.apache.org
# Version required:     1.3b3
# Date created:         Sun Mar  1 13:41:17 PST 1998
# Whom:                 cjs@netbsd.org
#
# $NetBSD: Makefile,v 1.1 1998/03/05 08:02:22 cjs Exp $
# FreeBSD Id: Makefile,v 1.45 1998/02/25 06:23:55 asami Exp
#

DISTNAME=       apache_1.3b3
PKGNAME=        apache-1.3b3
WRKROOT=	${WRKDIR}/apache_1.3b3
WRKSRC=         ${WRKROOT}/src
CATEGORIES=	www
MASTER_SITES=   http://www.apache.org/dist/

MAINTAINER=	cjs@netbsd.org

CONFIGURE_SCRIPT=Configure
HAS_CONFIGURE=	YES

CONF_DIR=   ${PREFIX}/http/conf
MAN1=   apachectl.1 htpasswd.1
MAN8=   httpd.8

# Set this for local-supplied patch, e.e.
# VERS_ID = mods-1.0/me

post-build:
	(cd ${WRKSRC}/support && make)

post-patch:
	@cd ${WRKROOT}/conf && \
	for I in httpd.conf-dist access.conf-dist srm.conf-dist; do \
	    sed -e "s#@@ServerRoot@@#${PREFIX}/http#g" < $${I} > $${I}.new; \
	    mv $${I}.new $${I}; \
	done
.if defined(VERS_ID)
	@cd ${WRKSRC} && \
	mv Configuration Configuration.old && \
	sed 's;^#*OPTIM=.*;OPTIM= -DSERVER_SUBVERSION=\\"${VERS_ID}\\";' \
	< Configuration.old > Configuration
.endif

do-install:
	install -d -m 755 -o bin -g bin ${CONF_DIR} ${PREFIX}/http/htdocs \
		${PREFIX}/http/icons ${PREFIX}/http/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/httpd ${PREFIX}/sbin
	cd ${WRKSRC}/support && \
		${INSTALL_PROGRAM} htdigest htpasswd dbmmanage logresolve \
		${PREFIX}/bin
	cd ${WRKSRC}/support && \
		${INSTALL_SCRIPT} rotatelogs apachectl log_server_status \
		${PREFIX}/sbin
	${INSTALL_DATA} -o nobody ${WRKROOT}/icons/* ${PREFIX}/http/icons
	${INSTALL_MAN} ${WRKSRC}/support/httpd.8 \
		${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/support/htpasswd.1 \
		       ${WRKSRC}/support/apachectl.1 \
		${PREFIX}/man/man1
	cd ${WRKROOT}/conf && \
	for file in httpd.conf srm.conf access.conf ; do \
	    if [ ! -f ${CONF_DIR}/$$file ] ; then \
		${INSTALL_DATA} $$file-dist ${CONF_DIR}/$$file ; \
	    fi ; \
	    ${INSTALL_DATA} $$file-dist ${CONF_DIR} ; \
	done
	cd ${WRKROOT}/conf && \
	for file in mime.types magic ; do \
	    if [ ! -f ${CONF_DIR}/$$file ] ; then \
		${INSTALL_DATA} $$file ${CONF_DIR} ; \
	    fi ; \
	    ${INSTALL_DATA} $$file ${CONF_DIR}/$${file}-dist ; \
	done

.include <bsd.port.mk>
