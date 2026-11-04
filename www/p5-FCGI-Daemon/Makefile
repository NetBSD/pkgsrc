# $NetBSD: Makefile,v 1.1 2026/11/04 13:46:52 ast Exp $

PKGBASE=	FCGI-Daemon
DISTNAME=	${PKGBASE}-0.20220206
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	ast@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/FCGI-Daemon
COMMENT=	Perl-aware Fast CGI daemon for use with nginx web server
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	perl:run

DEPENDS+=	p5-FCGI>=0.82:../../www/p5-FCGI
DEPENDS+=	p5-BSD-Resource>=1.29:../../devel/p5-BSD-Resource
DEPENDS+=	p5-FCGI-ProcManager>=0.28:../../www/p5-FCGI-ProcManager

FCGID_EG_DIR=	share/examples/fcgi-daemon
FCGID_NGINX=	nginx/common.conf nginx/ikiwiki.conf nginx/sample.conf

INSTALLATION_DIRS+=	${FCGID_EG_DIR} ${FCGID_EG_DIR}/nginx
INSTALLATION_DIRS+=	${PERL5_SUB_INSTALLVENDORMAN3DIR}
INSTALLATION_DIRS+=	${PERL5_SUB_INSTALLVENDORLIB}/FCGI

REPLACE_PERL=	lib/FCGI/Daemon.pm

RCD_SCRIPTS=	fcgi_daemon

do-install:
	${INSTALL_SCRIPT} \
		${WRKSRC}/blib/lib/FCGI/Daemon.pm \
			${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/FCGI
	${INSTALL_MAN} \
		${WRKSRC}/blib/man3/FCGI::Daemon.3 \
			${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORMAN3DIR}

post-install:
.for file in ${FCGID_NGINX}
	${INSTALL_DATA} ${WRKSRC}/examples/${file} \
		${DESTDIR}${PREFIX}/${FCGID_EG_DIR}/nginx
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
