# $NetBSD: Makefile,v 1.30 2022/06/28 11:37:11 wiz Exp $
#

DISTNAME=	CGI-Kwiki-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Quickie Wiki that is not too Tricky
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.0,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
#DEPENDS+=	{perl>=5.10.0,p5-Locale-Maketext>=1.08}:../../misc/p5-Locale-Maketext

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/CGI-Kwiki/.packlist

.include "../../mk/bsd.prefs.mk"

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
