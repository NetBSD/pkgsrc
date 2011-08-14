# $NetBSD: Makefile,v 1.20 2011/08/14 16:05:59 obache Exp $

DISTNAME=	HTTPD-User-Manage-1.66
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5hum
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTPD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://stein.cshl.org/~lstein/user_manage/
COMMENT=	Perl script/modules for managing web access control

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/HTTPD-User-Manage/.packlist
REPLACE_PERL=		user_manage
INSTALLATION_DIRS=	bin libexec/cgi-bin share/doc/user_manage

PKG_SYSCONFSUBDIR?=	httpd

SUBST_CLASSES+=		um
SUBST_STAGE.um=		pre-configure
SUBST_FILES.um=		user_manage
SUBST_VARS.um=		PKG_SYSCONFDIR

post-extract:
	chmod -x ${WRKSRC}/lib/HTTPD/UserAdmin/DBM.pm

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/user_manage ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/user_manage \
		${DESTDIR}${PREFIX}/libexec/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/user_manage.html \
		${DESTDIR}${PREFIX}/share/doc/user_manage/user_manage.html

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
