# $NetBSD: Makefile,v 1.51 2022/06/28 11:36:48 wiz Exp $

DISTNAME=	po4a-0.66
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mquinson/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://po4a.org/
COMMENT=	Tool for using gettext where it was not intended to be used
LICENSE=	gnu-gpl-v2

DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	p5-gettext>=1.01:../../devel/p5-gettext
DEPENDS+=	p5-SGMLS-[0-9]*:../../textproc/p5-SGMLS
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Pod-Parser-[0-9]*:../../textproc/p5-Pod-Parser
DEPENDS+=	p5-Text-WrapI18N-[0-9]*:../../textproc/p5-Text-WrapI18N
DEPENDS+=	p5-PerlIO-utf8_strict-[0-9]*:../../devel/p5-PerlIO-utf8_strict
DEPENDS+=	p5-Unicode-LineBreak-[0-9]*:../../textproc/p5-Unicode-LineBreak
DEPENDS+=	p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny
# kpsewhich
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
# article.cls
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

USE_TOOLS+=		pkg-config perl:run msgmerge:run msgfmt:run

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/po4a/.packlist

REPLACE_PERL=		msguntypot po4a po4a-gettextize po4a-normalize
REPLACE_PERL+=		po4a-translate po4a-updatepo
REPLACE_PERL+=		lib/Locale/Po4a/*

MAKE_ENV+=		COLUMNS=76

# work around not to set PATH to msgmerge, please somebody to fix correctly
SUBST_CLASSES+=		path
SUBST_FILES.path=	po4a
SUBST_MESSAGE.path=	Fix msgmerge command path (not found)
SUBST_STAGE.path=	pre-configure
SUBST_SED.path=		-e 's|\"msgmerge\"|\"${PREFIX}/bin/msgmerge\"|;'

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
