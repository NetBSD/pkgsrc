# $NetBSD: Makefile,v 1.1.1.1 2004/05/13 09:22:30 mjl Exp $
#

DISTNAME=       	CGI-Kwiki-0.18
PKGNAME=        	p5-${DISTNAME}
SVR4_PKGNAME=		p5ckw
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.kwiki.org/
COMMENT=		A Quickie Wiki that's not too Tricky

DEPENDS+=		p5-Test-Simple>=0.47:../../devel/p5-Test-Simple
DEPENDS+=		p5-Locale-Maketext>=1.08:../../misc/p5-Locale-Maketext

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI-Kwiki/.packlist

.include "../../mk/bsd.prefs.mk"

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
