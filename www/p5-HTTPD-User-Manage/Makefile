# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:51 veego Exp $

DISTNAME=	HTTPD-User-Manage-1.58
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hum
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTPD/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://stein.cshl.org/~lstein/user_manage/
COMMENT=	Perl script/modules for managing web access control

USE_PERL5=              # defined
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/HTTPD-User-Manage/.packlist
REPLACE_PERL=		user_manage

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-patch:
	@${MV} ${WRKSRC}/user_manage ${WRKSRC}/user_manage.old
	@${SED} -e "s+__PREFIX__+${PREFIX}+g" \
		${WRKSRC}/user_manage.old > ${WRKSRC}/user_manage

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/user_manage ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/user_manage ${PREFIX}/libexec/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/user_manage
	${INSTALL_DATA} ${WRKSRC}/user_manage.html \
		${PREFIX}/share/doc/user_manage/user_manage.html

.include "../../mk/bsd.pkg.mk"
