# $NetBSD: Makefile,v 1.6 2001/11/26 06:50:31 jlam Exp $

DISTNAME=		CGI-Application-1.2
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cga
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		jlam@netbsd.org
COMMENT=		perl5 module to create sophisticated, reusable web-based applications

DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Application/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
