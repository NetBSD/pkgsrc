# $NetBSD: Makefile,v 1.5 2001/11/26 06:50:30 jlam Exp $
#

DISTNAME=		Apache-Session-1.53
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ase
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module to provide persistent storage

DEPENDS+=		p5-Storable>=1.0.11:../../devel/p5-Storable/
DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5/

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Session/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
