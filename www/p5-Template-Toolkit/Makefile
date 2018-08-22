# $NetBSD: Makefile,v 1.50 2018/08/22 09:47:54 wiz Exp $

DISTNAME=	Template-Toolkit-2.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.template-toolkit.org/
#HOMEPAGE=	http://search.cpan.org/dist/Template-Toolkit/
COMMENT=	Perl5 text template and dynamic web page integration toolkit
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-AppConfig>=1.56:../../devel/p5-AppConfig
# recommended because of default-plugin
DEPENDS+=	p5-Image-Info-[0-9]*:../../graphics/p5-Image-Info
DEPENDS+=	p5-Pod-POM-[0-9]*:../../textproc/p5-Pod-POM

PERL5_PACKLIST=	auto/Template/.packlist

MAKE_PARAMS=	TT_ACCEPT=y

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
