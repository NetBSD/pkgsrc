# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:24 tv Exp $
#
# NOTE: This package is *BETA*.  If it doesn't work, then check the
#	modperl-2.0 mailing lists for help.

DISTNAME=		mod_perl-1.99_14
PKGNAME=		ap2-perl-1.99.14
PKGREVISION=	1
CATEGORIES=		www perl5
MASTER_SITES=		http://perl.apache.org/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

CONFLICTS=		ap-perl-[0-9]*

USE_BUILDLINK3=		yes
APACHE_MODULE=		# defined
PERL5_REQD+=		5.6.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

MAKE_PARAMS+=		MP_APXS=${APXS}

MODPERLDOCSDIR=	${PREFIX}/share/doc/mod_perl

post-install:
	${INSTALL_DATA_DIR} ${MODPERLDOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${MODPERLDOCSDIR}

.include "../../lang/perl5/module.mk"
.include "../../www/apache2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
