# $NetBSD: Makefile,v 1.3 2000/08/28 23:06:00 jlam Exp $
#

DISTNAME=       	CGI.pm-2.72
PKGNAME=        	p5-CGI-2.72
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		christos@netbsd.org

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/.packlist

# These perl packages install their own versions of CGI.pm.
#
CONFLICTS=		perl-5.[0-5]* perl-5.6.0{,nb1}

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
