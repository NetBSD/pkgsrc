# $NetBSD: Makefile,v 1.2 2000/08/27 10:37:03 jlam Exp $
#

DISTNAME=       ApacheDBI-0.87
PKGNAME=        ap-DBI-0.87
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/MERGL/}

MAINTAINER=	packages@netbsd.org

DEPENDS+=	ap-perl-*:../../www/ap-perl
DEPENDS+=	apache-1.3.*:../../www/apache

USE_PERL5=	# defined
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Apache/DBI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
