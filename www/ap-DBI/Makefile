# $NetBSD: Makefile,v 1.3 2001/02/17 17:21:42 wiz Exp $
#

DISTNAME=       ApacheDBI-0.87
PKGNAME=        ap-DBI-0.87
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/MERGL/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 Apache modules for DBI connections

DEPENDS+=	ap-perl-*:../../www/ap-perl
DEPENDS+=	apache-1.3.*:../../www/apache

USE_PERL5=	# defined
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Apache/DBI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
