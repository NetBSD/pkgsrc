# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:32 jlam Exp $

DISTNAME=		CGI-Minimal-1.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cgm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		perl5 module for simple CGI scripts

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Minimal/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
