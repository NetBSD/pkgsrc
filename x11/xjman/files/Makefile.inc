NROFF=		jgnroff -Tnippon
MANDIR=		${PREFIX}/${XJMANDIR}
TMACDIR=	${LOCALBASE}/share/groff/tmac
CATDEPS=	${TMACDIR}/tmac.andocj \
		${TMACDIR}/tmac.docj \
		${TMACDIR}/mdoc/doc-ditroffj \
		${TMACDIR}/mdoc/doc-commonj \
		${TMACDIR}/mdoc/doc-nroffj \
		${TMACDIR}/mdoc/doc-symsj
