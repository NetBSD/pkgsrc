# $NetBSD: Makefile,v 1.21 2006/01/24 07:32:43 wiz Exp $

DISTNAME=	mod_perl-2.0.1
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://perl.apache.org/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://perl.apache.org/
COMMENT=	Module that embeds a Perl interpreter into Apache

CONFLICTS=	ap-perl-[0-9]*

APACHE_MODULE=		# defined
PERL5_PACKLIST=		auto/mod_perl2/.packlist

MAKE_PARAMS+=		MP_APXS=${APXS}

MODPERLDOCSDIR=	${PREFIX}/share/doc/mod_perl

post-install:
	${INSTALL_DATA_DIR} ${MODPERLDOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${MODPERLDOCSDIR}

.include "../../lang/perl5/module.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
