# $NetBSD: Makefile,v 1.3 2001/09/19 03:44:39 mjl Exp $
#

DISTNAME=		Apache-Session-1.53
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module to provide persistent storage

DEPENDS+=		p5-Storable>=1.0.11:../../devel/p5-Storable/
DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5/

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Session/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
