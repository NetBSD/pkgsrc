# $NetBSD: Makefile,v 1.3 2002/11/19 23:22:41 jlam Exp $
#
# NOTE: This package is *BETA*.  If it doesn't work, then check the
#	modperl-2.0 mailing lists for help.

DISTNAME=		mod_perl-1.99_07
PKGNAME=		ap2-perl-1.99.7
CATEGORIES=		www perl5
MASTER_SITES=		http://perl.apache.org/dist/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

USE_BUILDLINK2=		# defined
PERL5_REQD=		5.6.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

MAKE_PARAMS+=		MP_APXS=${APXS}

post-install:
	${CP} -R ${WRKSRC}/docs ${PREFIX}/share/doc/html/mod_perl

.include "../../lang/perl5/module.mk"
.include "../../www/apache2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
