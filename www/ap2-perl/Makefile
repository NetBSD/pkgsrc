# $NetBSD: Makefile,v 1.12 2004/04/24 22:46:12 jlam Exp $
#
# NOTE: This package is *BETA*.  If it doesn't work, then check the
#	modperl-2.0 mailing lists for help.

DISTNAME=		mod_perl-1.99_12
PKGNAME=		ap2-perl-1.99.12
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		http://perl.apache.org/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

CONFLICTS=		ap-perl-[0-9]*

USE_BUILDLINK2=		# defined
APACHE_MODULE=		# defined
PERL5_REQD+=		5.6.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

MAKE_PARAMS+=		MP_APXS=${APXS}

MODPERLDOCSDIR=	${PREFIX}/share/doc/html/mod_perl

post-install:
	${INSTALL_DATA_DIR} ${MODPERLDOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${MODPERLDOCSDIR}

.include "../../lang/perl5/module.mk"
.include "../../www/apache2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
