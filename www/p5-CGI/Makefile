# $NetBSD: Makefile,v 1.4 2000/08/29 19:14:28 jlam Exp $
#

DISTNAME=       	CGI.pm-2.72
PKGNAME=        	p5-CGI-2.72
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		christos@netbsd.org

# Older perl packages install their own versions of CGI.pm.
DEPENDS+=		perl>=5.6.0nb2:../../lang/perl5-current

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
