# $NetBSD: Makefile,v 1.9 2004/04/27 05:44:23 snj Exp $

DISTNAME=	HTTPD-User-Manage-1.58
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hum
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTPD/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://stein.cshl.org/~lstein/user_manage/
COMMENT=	Perl script/modules for managing web access control

USE_BUILDLINK3=		YES
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/HTTPD-User-Manage/.packlist
REPLACE_PERL=		user_manage

PKG_SYSCONFSUBDIR?=	httpd

post-patch:
	cd ${WRKSRC}; for file in user_manage; do			\
		${SED} -e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			$${file} > $${file}.fixed;			\
		if [ -x $${file} ]; then				\
			${CHMOD} +x $${file}.fixed;			\
		fi;							\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/user_manage ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/user_manage ${PREFIX}/libexec/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/user_manage
	${INSTALL_DATA} ${WRKSRC}/user_manage.html \
		${PREFIX}/share/doc/user_manage/user_manage.html

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
