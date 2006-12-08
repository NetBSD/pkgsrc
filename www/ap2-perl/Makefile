# $NetBSD: Makefile,v 1.26 2006/12/08 23:34:11 xtraeme Exp $

DISTNAME=	mod_perl-2.0.3
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
CATEGORIES=	www perl5
MASTER_SITES=	http://perl.apache.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.apache.org/
COMMENT=	Module that embeds a Perl interpreter into Apache

CONFLICTS=	ap-perl-[0-9]* p5-Apache-Test-[0-9]*

PKG_APACHE_ACCEPTED=	apache2 apache22

APACHE_MODULE=		# defined
PERL5_PACKLIST=		auto/mod_perl2/.packlist

MAKE_PARAMS+=		MP_APXS=${APXS}

MODPERLDOCSDIR=	${PREFIX}/share/doc/mod_perl

post-install:
	${INSTALL_DATA_DIR} ${MODPERLDOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${MODPERLDOCSDIR}

.include "../../lang/perl5/module.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
